#!/bin/bash


args[0] = '[]'
echo $?
ans[0]=0
args[1]="[0]"
ans[1]=1
args[2]="[-1]"
ans[2]=1
args[3]="[1]"
ans[3]=1
args[4]="[1,1]"
ans[4]=0
args[5]="[0,0][0,0]"
ans[5]=4
args[6]="[0,1][0,0]"
ans[6]=1
args[7]="[1,1,1][1,1,1][1,1,1]"
ans[7]=1
args[8]="[2147483647,2147483647,2147483647][2147483647,2147483647,2147483647][2147483647,2147483647,2147483647]"
ans[8]=1
args[9]="[-2147483648,-2147483648,-2147483648][-2147483648,-2147483648,-2147483648][-2147483648,-2147483648,-2147483648]"
ans[9]=1

index=10
maxtest=$index+4
n[0]=99
m[0]=99
ans[index+0]=1
n[1]=999
m[1]=99
ans[index+1]=1
n[2]=99
m[2]=999
ans[index+2]=1
n[3]=999
m[3]=999
ans[index+3]=1
n[4]=9999
m[4]=9999
ans[index+4]=1


for i in {0..4}
do
  args[index+i]=""
  for j in {1..$m[i]}
  do
    args[index+i]=$args[index+i]+"[2147483647"
    for k in {1..$n[i]}
    do
      args[index+i]=$args[index+i]+",2147483647"
    done
    args[index+i]=$args[index+i]+"]"
  done
done


for i in {0..$maxtest}
do
  ./main.run $args[i]
  a=$? 
  if [ $a -eq $ans[i] ]; then
    echo "test $i - ok"
  else
    echo "test $i - wrong - $a : $ans[i]" 
  fi
done


