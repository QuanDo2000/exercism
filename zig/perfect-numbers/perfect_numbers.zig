pub const Classification = enum {
    deficient,
    perfect,
    abundant,
};

fn aliquot(n: u64) u64 {
    var s: u64 = 0;
    for (1..n) |i| {
        if (n % i == 0) s += i;
    }
    return s;
}

/// Asserts that `n` is nonzero.
pub fn classify(n: u64) Classification {
    const sum: u64 = aliquot(n);
    if (n == sum) return .perfect;
    if (n < sum) return .abundant;
    return .deficient;
}
