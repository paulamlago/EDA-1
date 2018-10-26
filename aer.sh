#!/bin/sh

# Command Line Interface to compile and test AceptaElReto scripts
# Errors:
# 1 - getopt not installed
# 2 - Getopt error
# 3 - No problem ID provided

set -o errexit -o pipefail -o noclobber -o nounset

BUILD_FOLDER="./bin"
SOURCE_FOLDER="./src"
AER_URL="https://aceptaelreto.com"
COOKIES_FILE="cookieJar"
USER_AGENT_ARRAY=("DavoScript xD/4.20" "Mozilla/5.0 (PLAYSTATION 3; 3.55)" "Mozilla/5.0 (Nintendo 3DS; U; ; en) Version/1.7412.EU" "Mozilla/5.0 (Linux; U; en-US) AppleWebKit/528.5+ (KHTML, like Gecko, Safari/528.5+) Version/4.0 Kindle/3.0 (screen 600x800; rotate)" "AppleTV6,2/11.1" "Mozilla/5.0 (Windows; U; Win95; en-US; rv:1.5) Gecko/20031007 Firebird/0.7" "Mozilla/2.0 (compatible; MSIE 4.0; Windows 98)" "Mozilla/4.0 (compatible; MSIE 6.0; AOL 6.0; Windows NT 5.1)" "Mozilla/5.0 (X11; U; Linux; C) AppleWebKit/533.3 (KHTML, like Gecko) QtCarBrowser Safari/533.3" "Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; Valve Steam GameOverlay/1513371133; ) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.62 Safari/537.36" "Nokia3310-1/20.0.04" "Nokia3250/2.0 (04.21) SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1 UP.Link/6.5.1.3.0 Novarra-Vision/7.3" "BlackBerry8100/4.5.0.124 Profile/MIDP-2.0 Configuration/CLDC-1.1 VendorID/100")
USER_AGENT=${USER_AGENT_ARRAY[$(date +%s) % ${#USER_AGENT_ARRAY[@]} ]}
COMMENT=""
# TODO: Change comment with -m

#Check if getopt is installed (but i'm pretty sure it is)
! getopt --test > /dev/null
if [[ ${PIPESTATUS[0]} -ne 4 ]]; then
    echo "getopt not installed"
    exit 1
fi

! PARSE=$(getopt --options=dibrteu --longoptions=download,init,build,run,test,edit,upload --name "$0" -- "$@")
eval set -- "$PARSE"
if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
    exit 2
fi

if [[ $# -le 2 ]]; then
    echo "Usage: $0 [options] <problem number/-a>"
    echo ""
    echo "You have to create a folder for each problem that will have:"
    echo " - A file called <problem number>.cpp"
    echo " - Optional: A file called in.txt which will be piped to the program with the --test option"
    echo ""
    echo "Options:"
    echo "-i, --init        Creates a file for a problem in $SOURCE_FOLDER"
    echo "-b, --build       Builds the file to $BUILD_FOLDER/<problem number>"
    echo "-r, --run         Runs the file $BUILD_FOLDER/<problem number>"
    echo "-t, --test        Pipes the file $SOURCE_FOLDER/<problem number>/in.txt to the problem"
    echo "-e, --edit        Opens the file in subl3"
    echo "-d, --download    Downloads problem description and input/output files from AceptaElReto"
    echo "-u, --upload      Uploads the problem to $AER_URL"
    echo "--login           DEBUG, only log-in"
    echo "-a                Performs the operation for all problems"
    echo ""
    echo "Work In Progress"
    echo "David Davó - 2018"
    echo "https://gitlab.com/daviddavo/AceptaElReto"
    exit 3
fi

b=n r=n t=n i=n d=n a=n e=n login=n upload=n
while true; do
    case "$1" in
        -i|--init)
            i=y
            shift
            ;;
        -b|--build)
            b=y
            shift
            ;;
        -r|--run)
            r=y
            shift
            ;;
        -t|--test)
            t=y
            shift
            ;;
        -e|--edit)
            e=y
            shift
            ;;
        -d|--download)
            d=y
            shift
            ;;
        -a)
            a=y
            shift
            ;;
        --login)
            login=y
            shift
            ;;
        -u|--upload)
            upload=y
            shift
            ;;
        --)
            shift
            break
            ;;
    esac
done

if [[ $# -ne 1 ]]; then
    echo "Please enter the problem id"
    exit 3
fi

if [[ $i = y ]]; then
    mkdir -p $SOURCE_FOLDER/$1
    touch $SOURCE_FOLDER/$1/$1.cpp
    subl3 $SOURCE_FOLDER/$1/$1.cpp
    # Todo: Download test cases from AceptaElReto.com
fi

download_sample() {
    # https://www.aceptaelreto.com/pub/problems/v002/00/sam/sample200.zip
    INTERVAL_CODE=$(printf v%03d $(($1/100)))
    NUMBER_CODE=$(printf %02d $(($1%100)))
    wget -A "$USER_AGENT" "$AER_URL/pub/problems/$INTERVAL_CODE/$NUMBER_CODE/sam/sample$1.zip" -O "$SOURCE_FOLDER/$1/sample.zip" -q
    unzip -q "$SOURCE_FOLDER/$1/sample.zip" -d "$SOURCE_FOLDER/$1"
    echo "" >> "$SOURCE_FOLDER/$1/sample.in"
    rm "$SOURCE_FOLDER/$1/sample.zip"
}

# $1 => userName
# $2 => passWord
login() {
    curl -b $COOKIES_FILE -c $COOKIES_FILE -v -X POST -A "$USER_AGENT" "$AER_URL/bin/login.php" -F "loginForm_username=$1" -F "loginForm_password=$2" -F "commit=Enter"
}

# TODO: Check if login failed by checking if the cookie acrsession exists
interactive_login() {
    response=y
    while [[ $response = y ]]; do
        read -p "Please enter your e-mail: " username
        read -s -p "Please enter your password: " password
        login $username $password

        cookie=$(awk -F "\t" '$6=="acrsession" {print $7}' $COOKIES_FILE)
        if [[ $cookie = "" ]]; then
            read -p "There has been an error trying to log in. Retry? (y/n) " response
        else
            response=n
        fi
    done
}

upload_problem() {
    curl -b $COOKIES_FILE -c $COOKIES_FILE -X POST -A "$USER_AGENT" "$AER_URL/bin/submitproblem.php" -F "id=$1" -F "language=CPP" -F "comment=$COMMENT" -F "cat=-1" -F "inputFile=@$SOURCE_FOLDER/$1/$1.cpp;type=text/x-c++src" -F "sentCode=sentCodeFile" -F "currentPage=/problem/send.php?id=$1" -F "immediateCode=" -i
    echo "Uploaded using $USER_AGENT"
}

if [[ $upload = y ]]; then
    response=y
    if [[ $(awk -F "\t" '$6=="acrsession" {print $5}' $COOKIES_FILE) -le $(date +%s) ]]; then
        read -p "Session expired, log in again? (y/n) " response
        if [[ $response = y ]]; then
            interactive_login
        fi
    fi

    if [[ $response = y ]]; then
        upload_problem $1
    fi
fi

if [[ $login = y ]]; then
    interactive_login
fi

if [[ $d = y ]]; then
    if [[ $a = y ]]; then
        #TODO: Run for every folder in $SOURCE_FOLDER
        echo "Not implemented"
    fi
    download_sample $1
fi

if [[ $b = y ]]; then
    if [ ! -d $BUILD_FOLDER ]; then
        mkdir -p $BUILD_FOLDER
    fi
    echo "Building $1 to $BUILD_FOLDER/$1"
    g++ -std=c++11 $SOURCE_FOLDER/$1/$1.cpp -o $BUILD_FOLDER/$1
fi

if [[ $r = y ]]; then
    echo "Running $1"
    $BUILD_FOLDER/$1
fi

if [[ $t = y ]]; then
    echo "Testing $1 from file $SOURCE_FOLDER/$1/sample.in"
    if [[ ! -f $SOURCE_FOLDER/$1/sample.in ]]; then
        echo "File sample.in doesn't exist, downloading"
        download_sample $1
    fi
    cat $SOURCE_FOLDER/$1/sample.in
    echo "Output:"
    $BUILD_FOLDER/$1 < $SOURCE_FOLDER/$1/sample.in
    echo "Expected output:"
    cat $SOURCE_FOLDER/$1/sample.out
    #TODO: Test if output is fine
fi

if [[ $e = y ]]; then
    echo "Editing $SOURCE_FOLDER/$1/$1.cpp"
    subl3 "$SOURCE_FOLDER/$1/$1.cpp"
fi
