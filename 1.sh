# =======================================================
# Name: 1.c
# Author: Tathagata Talukdar
# Description: Use soft link, hard link and fifo file
# Date: 5th Sep, 2023
# =======================================================
ln -s textfile1.txt soft_link
ln textfile1.txt hard_link
mkfifo fifo_file