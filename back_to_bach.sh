
#!/usr/bin/bash


read  n;s=0;
for i in `seq $n`
do
    read m;
    if [ $m -gt 0 ];
    then
	s=`expr $s + $m`;
    fi
done
echo $s;

    
