const std = @import("std");
const mem = std.mem;
const ascii = std.ascii;

pub fn rotate(allocator: mem.Allocator, text: []const u8, shiftKey: u5) mem.Allocator.Error![]u8 {
    var ans = std.ArrayList(u8).init(allocator);
    defer ans.deinit();

    for (text) |ch| {
        var new_ch: u8 = ch;
        if (ascii.isLower(ch)) {
            new_ch = @mod(ch - 'a' + shiftKey, 26);
            new_ch += 'a';
        } else if (ascii.isUpper(ch)) {
            new_ch = @mod(ch - 'A' + shiftKey, 26);
            new_ch += 'A';
        }
        try ans.append(new_ch);
    }
    return ans.toOwnedSlice();
}
