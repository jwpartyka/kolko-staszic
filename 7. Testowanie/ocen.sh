make wzo
make brut
make gen

for ((i = 1; i <= 1000000; i++)) do
    echo $i
    ./gen $i > test.in
    ./wzo < test.in > wzo.out
    ./brut < test.in > brut.out
    diff -w -B wzo.out brut.out || break;
done
