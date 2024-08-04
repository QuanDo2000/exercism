const std = @import("std");
const mem = std.mem;

pub fn sum(allocator: mem.Allocator, factors: []const u32, limit: u32) !u64 {
    var multiples = std.hash_map.AutoHashMap(u64, void).init(allocator);
    defer multiples.deinit();

    for (factors) |factor| {
        if (factor == 0) continue;
        var num = factor;
        while (num < limit) : (num += factor) {
            try multiples.put(num, {});
        }
    }

    var ans: u64 = 0;
    var keys = multiples.keyIterator();
    while (keys.next()) |key| ans += key.*;
    return ans;
}
