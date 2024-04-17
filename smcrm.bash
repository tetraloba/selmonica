if test $# -lt 1; then
    echo "too few arguments";
    exit;
fi;

DIR="${HOME}/selmonica/"

for DATE in $@; do
    rm ${DIR}${DATE}.mp4 &&
    rm ${DIR}${DATE}/* &&
    rmdir ${DIR}${DATE};
done;
