const std = @import("std");
const mem = std.mem;
const ascii = std.ascii;

pub fn response(s: []const u8) []const u8 {
    const noWhite = mem.trim(u8, s, &ascii.whitespace);

    if (noWhite.len == 0) return "Fine. Be that way!";

    const yell = isAllCaps(noWhite);
    const question = noWhite[noWhite.len - 1] == '?';

    if (yell and question) return "Calm down, I know what I'm doing!";
    if (yell) return "Whoa, chill out!";
    if (question) return "Sure.";
    return "Whatever.";
}

fn isAllCaps(s: []const u8) bool {
    var hasUpper: bool = false;
    for (s) |c| {
        if (ascii.isLower(c)) return false;
        if (ascii.isUpper(c)) hasUpper = true;
    }
    return hasUpper;
}
