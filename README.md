# 使い方

## コマンドのインストール
### RTSP(Python)版
### RTSP(C++)版
必要なパッケージのインストール
```bash
sudo apt install build-essential pkg-config libopencv-dev;
```
get_frame.cppをコンパイル
```bash
g++ -o get_frame get_frame.cpp `pkg-config --cflags --libs opencv4`;
```
ビルドされた実行ファイル`get_frame`をコマンドとして登録
```bash
sudo mv get_frame /usr/local/bin/get_frame;
```
### USB(C++)版
必要なパッケージのインストール
```bash
sudo apt install build-essential pkg-config libopencv-dev;
```
get_frame_usb.cppをコンパイル
```bash
g++ -o get_frame_usb get_frame_usb.cpp `pkg-config --cflags --libs opencv4`;
```
ビルドされた実行ファイル`get_frame_usb`をコマンドとして登録
```bash
sudo mv get_frame_usb /usr/local/bin/get_frame_usb;
```

## 実行方法

### RTSP(C++)版
以下のように実行する。
```bash
get_frame <"URL of RTSP"> <"file name of output image">
```
指定したRTSPストリームから1フレーム切り出して、指定したファイル名で保存する。
### USB(C++)版
以下のように実行する。
```bash
get_frame_usb <"file name of output image">
```
指定したファイル名でキャプチャした画像が保存される。
USBカメラの選択は現時点で未対応。普通は`fswebcam`とか使った方が良い。
~~何故作ったのか~~ <- Raspberry Piで`fswebcam`が不安定だったため。

## 定期実行の登録
`crontab -ie`を実行し、例えば以下のように登録する。
```crontab
# make date dir for selmonica
0 0 * * * mkdir ~/selmonica/`date "+\%Y\%m\%d"`;
# capture per 1 minutes
* * * * * DATE=`date "+\%Y\%m\%d"`; URL="URL_OF_RTSP"; ls ~/selmonica/${DATE} | wc -l | xargs printf "${HOME}/selmonica/${DATE}/\%04d.jpg" | xargs /usr/local/bin/get_frame ${URL};
```
この例では毎分画像をキャプチャして`0000.jpg`, `0001.jpg`のように連番で保存する。
`ffmpeg`コマンドでタイムラプス動画などを作る時に便利。

## (おまけ) タイムラプス動画の作成
`ffmpeg`コマンドを使う。無ければ`sudo apt install ffmpeg -y`などでインストールすること。
例えば以下のように実行することで動画(.mp4)を生成できる。
```bash
ffmpeg -an -r 30 -i ~/selmonica/${DATE}/%04d.jpg -vcodec libx264 -pix_fmt yuv420p ~/selmonica/${DATE}.mp4;
```
`-an`はオーディオ無しの指定
`-r 30`はフレームレートを30fpsに指定
`-i ~/selmonica/${DATE}/%04d.jpg`でソースとなる画像を指定している。変数`${DATE}`には適切な値を入れること。(`20240404`等)
`~/selmonica/${DATE}.mp4`は出力する動画のパスである。
フルHDで1440フレームの場合、intel N100で1分弱かかった。
