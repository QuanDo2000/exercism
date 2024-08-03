const std = @import("std");
const mem = std.mem;

pub const ConversionError = error{
    InvalidInputBase,
    InvalidOutputBase,
    InvalidDigit,
};

/// Converts `digits` from `input_base` to `output_base`, returning a slice of digits.
/// Caller owns the returned memory.
pub fn convert(
    allocator: mem.Allocator,
    digits: []const u32,
    input_base: u32,
    output_base: u32,
) (mem.Allocator.Error || ConversionError)![]u32 {
    if (input_base < 2) return ConversionError.InvalidInputBase;
    if (output_base < 2) return ConversionError.InvalidOutputBase;

    var value: u32 = 0;
    for (digits) |digit| {
        if (digit >= input_base) return ConversionError.InvalidDigit;
        value = value * input_base + digit;
    }

    var ans = std.ArrayList(u32).init(allocator);
    defer ans.deinit();

    while (value > 0) : (value = @divFloor(value, output_base)) {
        try ans.insert(0, @mod(value, output_base));
    }
    if (ans.items.len == 0) try ans.append(0);

    return ans.toOwnedSlice();
}
