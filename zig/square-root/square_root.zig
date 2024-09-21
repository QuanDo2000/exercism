pub fn squareRoot(radicand: usize) usize {
    return @intFromFloat(@sqrt(@as(f64, @floatFromInt(radicand))));
}
