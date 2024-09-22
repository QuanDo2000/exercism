const std = @import("std");
const mem = std.mem;

pub const Item = struct {
    // This struct, as well as its fields and init method, needs to be implemented.
    weight: usize,
    value: usize,

    pub fn init(weight: usize, value: usize) Item {
        return Item{
            .weight = weight,
            .value = value,
        };
    }
};

pub fn maximumValue(allocator: mem.Allocator, maximumWeight: usize, items: []const Item) !usize {
    if (items.len == 0) return 0;

    const item = items[0];
    if (item.weight > maximumWeight) return 0;

    const pickValue = (maximumValue(allocator, maximumWeight - item.weight, items[1..]) catch 0) + item.value;

    const nullValue = maximumValue(allocator, maximumWeight, items[1..]) catch 0;
    return @max(pickValue, nullValue);
}
