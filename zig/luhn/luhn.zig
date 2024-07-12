const ascii = @import("std").ascii;

pub fn isValid(s: []const u8) bool {
    var l: usize = 0;
    for (s) |c| {
        if (ascii.isWhitespace(c)) {
            continue;
        } else if (ascii.isDigit(c)) {
            l += 1;
        } else {
            return false;
        }
    }
    if (l <= 1) return false;

    var sum: usize = 0;
    var idx: usize = 0;
    for (s) |c| {
        if (ascii.isDigit(c)) {
            var val = c - '0';
            if (l % 2 == idx % 2) val *= 2;
            if (val > 9) val -= 9;
            sum += val;
            idx += 1;
        }
    }
    return sum % 10 == 0;
}
