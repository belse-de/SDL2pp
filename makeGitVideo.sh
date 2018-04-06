#!/bin/bash

RES="1024x768"
#RES="640x480"
RATE="30"
PROJECT="sdl2pp"

GS_TITLE="--title $PROJECT"
#GS_LOGO="--logo logo.png"
GS_LOGO=""
#GS_DATE='--date-format "%FT%TZ"'
GS_DATE="--date-format %F"
#GS_HIDE="--hide bloom,date,dirnames,files,filenames,mouse,progress,tree,users,usernames"
GS_HIDE="--hide filenames"
#Camera mode (overview,track)
GS_CAM="--camera-mode overview"       
GS="gource $GS_TITLE $GS_LOGO $GS_DATE $GS_HIDE $GS_CAM"
#--seconds-per-day 1

# webm
$GS -$RES

exit
$GS -$RES -o - | ffmpeg -y -r $RATE -f image2pipe -vcodec ppm -i - -vcodec libvpx -b 10000K ../$PROJECT-gource.webm

#mp4
#gource -$RES -o - | ffmpeg -y -r $RATE -f image2pipe -vcodec ppm -i - -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 ../$PROJECT-gource.mp4

#gource -$RES -o ../$PROJECT-gource.ppm
#ffmpeg -y -r $RATE -f image2pipe -vcodec ppm -i../$PROJECT-gource.ppm -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 gource.mp4
exit
gource --date-format %F -1024x768 --seconds-per-day 1 --auto-skip-seconds 1 --hide date,dirnames,filenames,mouse,progress -r 30 -o - | ffmpeg -y -r 30 -f image2pipe -vcodec ppm -i - -vcodec libvpx -b:v 100000K -threads 3 ../hmm_toolbox-gource-100000K.webm

gource --date-format %F -1024x768 --seconds-per-day 1 --auto-skip-seconds 1 --hide date,dirnames,filenames,mouse,progress -r 30 -o - | ffmpeg -y -r 30 -f image2pipe -vcodec ppm -i - -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 3 -bf 0 ../hmm_toolbox-gource.mp4
