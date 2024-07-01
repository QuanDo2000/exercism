for subdir in ./zig/*/; do
    cd $subdir
    file=`find . -name 'test_*.zig'`
    echo `basename $file`
    zig test $file
    cd ../..
done