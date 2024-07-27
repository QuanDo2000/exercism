const std = @import("std");
const mem = std.mem;

fn closeBracket(c: u8) u8 {
    return switch (c) {
        '[' => ']',
        '{' => '}',
        '(' => ')',
        else => c,
    };
}

pub fn isBalanced(allocator: mem.Allocator, s: []const u8) !bool {
    const stack = try allocator.alloc(u8, 50);
    defer allocator.free(stack);

    var idx: usize = 0;
    for (s) |c| {
        switch (c) {
            '[', '{', '(' => {
                stack[idx] = closeBracket(c);
                idx += 1;
            },
            ']', ')', '}' => {
                if (idx > 0 and stack[idx - 1] == c) {
                    idx -= 1;
                } else return false;
            },
            else => continue,
        }
    }
    return idx == 0;
}
