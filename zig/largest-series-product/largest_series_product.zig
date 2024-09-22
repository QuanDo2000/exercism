const std = @import("std");
const ascii = std.ascii;

pub const SeriesError = error{
    InvalidCharacter,
    NegativeSpan,
    InsufficientDigits,
};

fn getProduct(digits: []const u8) SeriesError!u64 {
    var ans: u64 = 1;
    for (digits) |digit| {
        if (!ascii.isDigit(digit)) return SeriesError.InvalidCharacter;
        ans *= digit - '0';
    }
    return ans;
}

pub fn largestProduct(digits: []const u8, span: i32) SeriesError!u64 {
    if (digits.len < span) return SeriesError.InsufficientDigits;
    if (span < 0) return SeriesError.NegativeSpan;

    if (digits.len == 0 or span == 0) return 1;
    const newSpan = @as(usize, @intCast(span));

    var ans: u64 = 0;
    for (0..digits.len - newSpan + 1) |i| {
        const product = try getProduct(digits[i .. i + newSpan]);
        if (ans < product) ans = product;
    }
    return ans;
}
