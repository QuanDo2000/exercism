const std = @import("std");

pub fn isArmstrongNumber(num: u128) bool {
    var buf: [64]u8 = undefined;
    const strNum = std.fmt.bufPrint(&buf, "{d}", .{num}) catch unreachable;
    const numDigits: usize = strNum.len;

    var n: u128 = num;
    var sum: u128 = 0;
    while (n > 0) {
        const digit: u128 = n % 10;
        sum += std.math.pow(u128, digit, numDigits);
        n /= 10;
    }
    return sum == num;
}
