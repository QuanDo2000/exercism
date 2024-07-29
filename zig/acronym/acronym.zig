const std = @import("std");
const mem = std.mem;
const ascii = std.ascii;

pub fn abbreviate(allocator: mem.Allocator, words: []const u8) mem.Allocator.Error![]u8 {
    var ans = std.ArrayList(u8).init(allocator);
    var tokens = mem.tokenizeAny(u8, words, " -_");
    while (tokens.next()) |w| try ans.append(w[0] & '_');
    return ans.toOwnedSlice();
}
