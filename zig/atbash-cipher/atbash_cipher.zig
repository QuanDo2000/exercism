const std = @import("std");
const mem = std.mem;

/// Encodes `s` using the Atbash cipher. Caller owns the returned memory.
pub fn encode(allocator: mem.Allocator, s: []const u8) mem.Allocator.Error![]u8 {
    var ans = std.ArrayList(u8).init(allocator);

    var i: u8 = 0;
    for (s) |c| {
        const new_c = switch (c) {
            'a'...'z' => 'z' - (c - 'a'),
            'A'...'Z' => 'z' - (c - 'A'),
            '0'...'9' => c,
            else => continue,
        };
        if (i == 5) {
            try ans.append(' ');
            i = 0;
        }
        try ans.append(new_c);

        i += 1;
    }
    return ans.toOwnedSlice();
}

/// Decodes `s` using the Atbash cipher. Caller owns the returned memory.
pub fn decode(allocator: mem.Allocator, s: []const u8) mem.Allocator.Error![]u8 {
    var ans = std.ArrayList(u8).init(allocator);
    for (s) |c| {
        const new_c = switch (c) {
            'a'...'z' => 'z' - (c - 'a'),
            '0'...'9' => c,
            else => continue,
        };
        try ans.append(new_c);
    }
    return ans.toOwnedSlice();
}
