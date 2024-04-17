if test $# -lt 1; then
    echo "too few arguments";
    exit;
fi;

DIR="${HOME}/selmonica/"

for DATE in $@; do
    ffmpeg -an -r 30 -i ${DIR}${DATE}/%04d.jpg -vcodec libx264 -pix_fmt yuv420p ${DIR}${DATE}.mp4;
done;
