pub fn isValidIsbn10(s: []const u8) bool {
    var count: i32 = 10;
    var check: i32 = 0;
    for (s) |ch| switch (ch) {
        '0'...'9' => {
            const val = ch - '0';
            check += count * val;
            count -= 1;
        },
        'X' => {
            if (count != 1) return false;
            check += count * 10;
            count -= 1;
        },
        '-' => {},
        else => return false,
    };
    return count == 0 and @mod(check, 11) == 0;
}
