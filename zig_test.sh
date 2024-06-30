for file in "./zig/*/test_*.zig"; do
    echo `basename $file`
    zig test $file
done