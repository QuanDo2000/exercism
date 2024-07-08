const math = @import("std").math;

pub const ChessboardError = error{
    IndexOutOfBounds,
};

pub fn square(index: usize) ChessboardError!u64 {
    if (index <= 0 or index > 64) return ChessboardError.IndexOutOfBounds;
    return math.pow(u64, 2, index - 1);
}

pub fn total() u64 {
    return @as(u64, 0) -% 1;
}
