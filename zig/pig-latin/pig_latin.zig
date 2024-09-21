const std = @import("std");
const mem = std.mem;
const ascii = std.ascii;

fn isVowel(char: u8) bool {
    const slice = [_]u8{char};
    return ascii.indexOfIgnoreCase("aeiou", &slice) != null;
}

fn isConsonant(char: u8) bool {
    return ascii.isAlphabetic(char) and !isVowel(char);
}

fn isRule1(phrase: []const u8) bool {
    return (phrase.len > 0 and isVowel(phrase[0])) or
        (ascii.startsWithIgnoreCase(phrase, "xr")) or
        (ascii.startsWithIgnoreCase(phrase, "yt"));
}

fn isRule2(phrase: []const u8) bool {
    return (phrase.len > 0 and isConsonant(phrase[0]));
}

fn isRule3(phrase: []const u8) bool {
    const idx = ascii.indexOfIgnoreCase(phrase, "qu") orelse return false;
    for (0..idx) |i| {
        if (!isConsonant(phrase[i])) return false;
    }
    return true;
}

fn isRule4(phrase: []const u8) bool {
    const idx = ascii.indexOfIgnoreCase(phrase, "y") orelse return false;
    if (idx < 1) return false;
    for (0..idx) |i| {
        if (!isConsonant(phrase[i])) return false;
    }
    return true;
}

fn translateWord(allocator: mem.Allocator, word: []const u8) mem.Allocator.Error![]u8 {
    var ans = std.ArrayList(u8).init(allocator);
    defer ans.deinit();
    if (isRule1(word)) {
        try ans.appendSlice(word);
        try ans.appendSlice("ay");
    } else if (isRule3(word)) {
        const idx = ascii.indexOfIgnoreCase(word, "qu").? + 2;
        try ans.appendSlice(word[idx..]);
        try ans.appendSlice(word[0..idx]);
        try ans.appendSlice("ay");
    } else if (isRule4(word)) {
        const idx = ascii.indexOfIgnoreCase(word, "y").?;
        try ans.appendSlice(word[idx..]);
        try ans.appendSlice(word[0..idx]);
        try ans.appendSlice("ay");
    } else if (isRule2(word)) {
        var idx: usize = 0;
        while (isConsonant(word[idx])) {
            idx += 1;
        }
        try ans.appendSlice(word[idx..]);
        try ans.appendSlice(word[0..idx]);
        try ans.appendSlice("ay");
    }
    return ans.toOwnedSlice();
}

pub fn translate(allocator: mem.Allocator, phrase: []const u8) mem.Allocator.Error![]u8 {
    var ans = std.ArrayList(u8).init(allocator);
    defer ans.deinit();
    var tokens = mem.tokenizeAny(u8, phrase, " ");
    while (tokens.next()) |word| {
        if (ans.items.len > 0) try ans.append(' ');
        const newWord = try translateWord(allocator, word);
        try ans.appendSlice(newWord);
        allocator.free(newWord);
    }
    return ans.toOwnedSlice();
}
