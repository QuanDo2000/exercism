const std = @import("std");

const NUM_ALPHABETS: u16 = 26;

pub fn isIsogram(str: []const u8) bool {
    var letters = std.bit_set.IntegerBitSet(NUM_ALPHABETS).initEmpty();

    for (str) |c| {
        if (!std.ascii.isAlphabetic(c)) continue;
        const v = std.ascii.toLower(c) - 'a';
        if (letters.isSet(v)) return false;
        letters.set(v);
    }

    return true;
}
