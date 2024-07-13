const math = @import("std").math;

pub const Coordinate = struct {
    // This struct, as well as its fields and methods, needs to be implemented.
    x: f32,
    y: f32,

    pub fn init(x_coord: f32, y_coord: f32) Coordinate {
        return Coordinate{
            .x = x_coord,
            .y = y_coord,
        };
    }
    pub fn score(self: Coordinate) usize {
        const r: f32 = math.sqrt(self.x * self.x + self.y * self.y);
        if (r > 10) return 0;
        if (r > 5) return 1;
        if (r > 1) return 5;
        return 10;
    }
};
