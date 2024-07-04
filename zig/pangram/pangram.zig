const std = @import("std");

const NUM_ALPHABETS: u16 = 26;

pub fn isPangram(str: []const u8) bool {
    var letters = std.bit_set.IntegerBitSet(NUM_ALPHABETS).initEmpty();

    for (str) |c| {
        if (!std.ascii.isAlphabetic(c)) continue;
        letters.set(std.ascii.toLower(c) - 'a');
    }

    return letters.count() == NUM_ALPHABETS;
}
