pub const NucleotideError = error{Invalid};

pub const Counts = struct {
    a: u32 = 0,
    c: u32 = 0,
    g: u32 = 0,
    t: u32 = 0,
};

pub fn countNucleotides(s: []const u8) NucleotideError!Counts {
    var ans = Counts{};
    for (s) |c| switch (c) {
        'A' => ans.a += 1,
        'C' => ans.c += 1,
        'G' => ans.g += 1,
        'T' => ans.t += 1,
        else => return NucleotideError.Invalid,
    };
    return ans;
}
