const std = @import("std");
const bit_set = std.bit_set;

pub fn primes(buffer: []u32, comptime limit: u32) []u32 {
    if (limit < 2) return &.{};

    var ps = bit_set.StaticBitSet(limit + 1).initEmpty();

    var idx: u8 = 0;
    for (2..limit + 1) |i| {
        if (ps.isSet(i)) continue;
        buffer[idx] = @intCast(i);
        idx += 1;

        var n = i;
        while (n <= limit) : (n += i) {
            ps.set(n);
        }
    }
    return buffer[0..idx];
}
