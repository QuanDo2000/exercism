const io = @import("std").io;

pub fn convert(buffer: []u8, n: u32) []const u8 {
    var buff = io.fixedBufferStream(buffer);
    const writer = buff.writer();
    if (n % 3 == 0) writer.writeAll("Pling") catch unreachable;
    if (n % 5 == 0) writer.writeAll("Plang") catch unreachable;
    if (n % 7 == 0) writer.writeAll("Plong") catch unreachable;
    if (buff.pos == 0) writer.print("{d}", .{n}) catch unreachable;
    return buffer[0..buff.pos];
}
