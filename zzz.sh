ls -1 $@ > diff_ls
./ft_ls $@ > diff_my
opendiff diff_ls diff_my
#rm ~/Desktop/diff_ls ~/Desktop/diff_my
