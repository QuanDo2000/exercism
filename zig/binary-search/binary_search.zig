// Take a look at the tests, you might have to change the function arguments

pub fn binarySearch(comptime T: type, target: T, items: []const T) ?usize {
    if (items.len == 0) return null;

    var lo: usize = 0;
    var hi: usize = items.len;
    while (lo < hi) {
        const mid = (lo + hi) / 2;
        if (items[mid] == target) return mid;
        if (items[mid] > target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return null;
}
