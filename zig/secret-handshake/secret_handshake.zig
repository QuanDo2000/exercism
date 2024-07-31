const std = @import("std");
const mem = std.mem;
const enums = std.enums;

pub const Signal = enum {
    wink,
    double_blink,
    close_your_eyes,
    jump,
};

pub fn calculateHandshake(allocator: mem.Allocator, number: u5) mem.Allocator.Error![]const Signal {
    var actions = std.ArrayList(Signal).init(allocator);
    inline for (enums.values(Signal), .{ 1, 2, 4, 8 }) |field, bit|
        if (number & bit > 0) try if (number & 16 > 0) actions.insert(0, field) else actions.append(field);
    return actions.toOwnedSlice();
}
