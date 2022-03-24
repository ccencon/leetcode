#/bin/sh
#提交github自动化工具
#leetcode插件工作目录为当前目录，生成文件名类似1.xxxx.cpp
#此脚本会更改cpp名字并移动到相关目录，按固定格式操作readme，最后提交github
localPath=`pwd`
githubPath='https://github.com/ccencon/leetcode'
orderStep=50

dirName=""
GetDirectoty()
{
    beginIdx=`expr $1 - 1`
    beginIdx=`expr $beginIdx / $orderStep`
    beginIdx=`expr $beginIdx \* $orderStep + 1`
    endIdx=`expr $beginIdx + $orderStep - 1`
    dirName=`printf "leetcode_%04d_%04d" $beginIdx $endIdx`
    if [ -d "${dirName}" ]; then
        return
    fi
    #主目录README.md加入记录
    content=`printf "[leetcode_%04d_%04d](${githubPath}/leetcode_%04d_%04d)\040\040" $beginIdx $endIdx $beginIdx $endIdx`
    lines=`sed -n -e '/leetcode_[0-9][0-9][0-9][0-9]/=' README.md`
    insert=0
    if [ -n "$lines" ]; then
        for line in $lines; do
            str=`sed -n ${line}p README.md`
            number=${str:10:4}
            if [ $beginIdx -lt $number ]; then
                sed -i ${line}"i""${content}" README.md
                insert=1
                break 1
            fi
        done
    fi
    ##concent要用""括起来，如果不用""，shell按照IFS划分参数之后，空格前后将会被分割成两个参数
    if [ $insert -eq 0 ]; then
        echo -e "$content" >> README.md
    fi
    #创建新的文件夹
    mkdir ${dirName}
    mkdir ${dirName}/cpp
    touch ${dirName}/README.md
    #新目录README.md加入固定记录
    echo "# ${dirName}" >> ${dirName}/README.md
    echo "|order|question|cpp link|" >> ${dirName}/README.md
    echo "|:-|:-|:-|" >> ${dirName}/README.md

    echo -e "\033[32m info:\033[0m \033[34m${dirName}\033[0m create"
}

#$1:line $2:questionName $3:newFileName $4:order
insert_list()
{
    list=`printf "|[%04d](#%04d)|[$2](#%04d)|[cpp](${githubPath}/${dirName}/$3)|" $4 $4 $4`
    if [ $1 -eq 0 ]; then
        echo "${list}" >> ${dirName}/README.md
        echo >> ${dirName}/README.md
    else
        sed -i $1"i""${list}" ${dirName}/README.md
    fi
}

#$1:line $2:questionName $3:newFileName $4:order
insert_content()
{
    title=`printf "#### <span id=%04d>[$4] $2</span>" $4`
    urlline=`sed -n -e '/"title\": \"'${order}'\./=' url.json`
    urlline=`expr $urlline + 1`
    tt=`sed -n ${urlline}p url.json`
    tt=${tt#*: \"}
    tt=${tt%\"*}
    ques="题目链接：[${tt}](${tt})  "
    link=${githubPath}/${dirName}/$3
    cpplink="代码链接：[$link](${link})  "
    solut="解题思路："
    #$1==0时行尾插入
    if [ $1 -eq 0 ]; then
        echo "${title}" >> ${dirName}/README.md
        echo "${ques}" >> ${dirName}/README.md
        echo "${cpplink}" >> ${dirName}/README.md
        echo "${solut}" >> ${dirName}/README.md
    else
        line=$1
        sed -i ${line}"i""${title}" ${dirName}/README.md
        sed -i ${line}"a""${ques}" ${dirName}/README.md
        line=`expr $line + 1`
        sed -i ${line}"a""${cpplink}" ${dirName}/README.md
        line=`expr $line + 1`
        sed -i ${line}"a""${solut}" ${dirName}/README.md
    fi
}

for file in $localPath/*; do
    fileName=$(basename $file)
    order=`expr $fileName : '\([0-9]*\).*[.]cpp'`
    if [ -z "$order" ]; then
        continue
    fi
    pos=`expr ${#order} + 1`
    len=`expr ${#fileName} - 4 - $pos`
    questionName=${fileName:$pos:$len}
    GetDirectoty $order
    newFileName=`printf "leetcode_%04d.cpp" $order`
    if [ -f ${dirName}/cpp/${newFileName} ]; then
        echo -e "\033[32m info:\033[0m \033[33m${dirName}/cpp/${newFileName}\033[0m exist, ignore"
        continue
    fi
    \cp $fileName ${dirName}/cpp
    mv ${dirName}/cpp/${fileName} ${dirName}/cpp/${newFileName}
    mv $fileName ".back/"
    #向新目录内README.md插入新记录
    lines=`sed -n -e '/[[0-9][0-9][0-9][0-9]](/=' ${dirName}/README.md`
    if [ -n "$lines" ]; then
        insert=0
        lastline=0
        for line in $lines; do
            lastline=$line
            str=`sed -n ${line}p ${dirName}/README.md`
            number=${str:2:4}
            if [ $order -lt $number ]; then
                insert_list $line $questionName $newFileName $order
                content_line=`sed -n -e "/#### <span id=${number}/=" ${dirName}/README.md`
                insert_content $content_line $questionName $newFileName $order
                insert=1
                break 1
            fi
        done
        if [ $insert -eq 0 ]; then
            insert_list `expr $lastline + 1` $questionName $newFileName $order
            insert_content 0 $questionName $newFileName $order
        fi
    else
        insert_list 0 $questionName $newFileName $order
        insert_content 0 $questionName $newFileName $order
    fi
    echo -e "\033[32m info:\033[0m \033[33m${dirName}/cpp/${newFileName}\033[0m create"
done

if [[ $1 -eq 1 ]]; then
    git add .
    git commit -m "leetcode auto commit"
    git push
fi

chmod 0777 ./ -R
