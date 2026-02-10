#!/bin/bash
find -mindepth 1 -type d > temp.txt
grep -v /sparrow temp.txt > target_folders.txt
rm temp.txt
joblist='target_folders.txt'
njobs=`wc ${joblist} | awk '{print $1}'`

cwd=`pwd`
while IFS= read -r line
do
        folder="$line"   #`awk '(NR=='${i}'){print}' ${joblist}`
        cd ${folder}
        if [ "$(find ./ -type f -name "*.cpp")" ]; then
		for file in $(find ./ -type f -name "*.cpp" ! \( -name "*msvc*" \))
		do
			g++ -w -c -std=c++11 -fpermissive $file
		done
        fi

        cd ${cwd}
done < target_folders.txt
cd ${cwd}

rm target_folders.txt
find ./ -name *.o -exec rm {} \;
exit 0

