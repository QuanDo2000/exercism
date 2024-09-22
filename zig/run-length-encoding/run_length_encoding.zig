const std = @import("std");
const fmt = std.fmt;
const ascii = std.ascii;

pub fn encode(buffer: []u8, string: []const u8) []u8 {
    var count: usize = 1;
    var idx: usize = 0;
    for (0..string.len) |i| {
        const curr: u8 = string[i];
        var next: u8 = ' ';
        if (i == string.len - 1) {
            next = ' ';
        } else {
            next = string[i + 1];
        }
        if (i < string.len - 1 and string[i] == string[i + 1]) {
            count += 1;
        } else if (count > 1) {
            const tmp = fmt.bufPrint(buffer[idx..], "{}{c}", .{ count, curr }) catch "";
            idx += tmp.len;
            count = 1;
        } else {
            const tmp = fmt.bufPrint(buffer[idx..], "{c}", .{curr}) catch "";
            idx += tmp.len;
            count = 1;
        }
    }
    return buffer[0..idx];
}

pub fn decode(buffer: []u8, string: []const u8) []u8 {
    var count: usize = 0;
    var idx: usize = 0;
    for (0..string.len) |i| {
        const curr = string[i];
        if (ascii.isDigit(curr)) {
            count *= 10;
            count += curr - '0';
        } else {
            for (0..count) |_| {
                buffer[idx] = curr;
                idx += 1;
            }
            if (count == 0) {
                buffer[idx] = curr;
                idx += 1;
            }
            count = 0;
        }
    }
    return buffer[0..idx];
}
