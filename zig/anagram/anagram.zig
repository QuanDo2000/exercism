const std = @import("std");
const mem = std.mem;
const ascii = std.ascii;

fn countLetters(word: []const u8) [26]u8 {
    var counts = [_]u8{0} ** 26;
    for (word) |c| {
        if (ascii.isAlphabetic(c)) counts[ascii.toLower(c) - 'a'] += 1;
    }

    return counts;
}
fn isAnagram(w1: []const u8, w2: []const u8) bool {
    if (ascii.eqlIgnoreCase(w1, w2)) return false;

    const c1 = countLetters(w1);
    const c2 = countLetters(w2);

    return std.mem.eql(u8, &c1, &c2);
}

/// Returns the set of strings in `candidates` that are anagrams of `word`.
/// Caller owns the returned memory.
pub fn detectAnagrams(
    allocator: mem.Allocator,
    word: []const u8,
    candidates: []const []const u8,
) !std.BufSet {
    var ans = std.BufSet.init(allocator);
    for (candidates) |candidate| {
        if (isAnagram(word, candidate)) try ans.insert(candidate);
    }
    return ans;
}
