const std = @import("std");
const ascii = std.ascii;
const mem = std.mem;

/// Returns the counts of the words in `s`.
/// Caller owns the returned memory.
pub fn countWords(allocator: mem.Allocator, s: []const u8) !std.StringHashMap(u32) {
    var ans = std.StringHashMap(u32).init(allocator);

    const lower = try ascii.allocLowerString(allocator, s);
    defer allocator.free(lower);

    var tokens = mem.tokenizeAny(u8, lower, ":!?@$$%^&.,\"\t\n ");
    while (tokens.next()) |w| {
        const word = try allocator.dupe(u8, w);
        const wo = mem.trim(u8, word, "'");
        if (wo.len == 0) {
            allocator.free(word);
            continue;
        }

        const ptr = ans.getPtr(wo);
        if (ptr) |p| {
            p.* += 1;
        } else {
            const copy = try allocator.dupe(u8, wo);
            try ans.putNoClobber(copy, 1);
        }
        allocator.free(word);
    }
    return ans;
}
