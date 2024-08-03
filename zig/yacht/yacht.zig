pub const Category = enum {
    ones,
    twos,
    threes,
    fours,
    fives,
    sixes,
    full_house,
    four_of_a_kind,
    little_straight,
    big_straight,
    choice,
    yacht,
};

fn count_dice(dice: [5]u3) [6]u3 {
    var count: [6]u3 = .{ 0, 0, 0, 0, 0, 0 };
    for (dice) |d| {
        count[d - 1] += 1;
    }
    return count;
}

fn score_num(dice: [5]u3, num: i5) u32 {
    var ans: u32 = 0;
    for (dice) |d| {
        if (num == -1) ans += d;
        if (d == num) ans += @intCast(num);
    }
    return ans;
}

fn score_full_house(dice: [5]u3) u32 {
    const count = count_dice(dice);

    var ans: u32 = 0;
    for (0..6) |i| {
        if (count[i] == 1 or count[i] == 4 or count[i] == 5) return 0;
        ans += @truncate((i + 1) * count[i]);
    }
    return ans;
}

fn score_four_of_a_kind(dice: [5]u3) u32 {
    const count = count_dice(dice);

    for (0..6) |i| {
        if (count[i] == 4 or count[i] == 5) return @truncate((i + 1) * 4);
    }
    return 0;
}

fn score_yatch(dice: [5]u3) u32 {
    const count = count_dice(dice);

    for (0..6) |i| {
        if (count[i] == 5) return 50;
    }
    return 0;
}

fn score_straight(dice: [5]u3, category: Category) u32 {
    const count = count_dice(dice);

    for (0..6) |i| {
        if (count[i] != 1 and count[i] != 0) return 0;
    }
    if ((category == .little_straight and count[5] == 0) or
        (category == .big_straight and count[0] == 0)) return 30;
    return 0;
}

pub fn score(dice: [5]u3, category: Category) u32 {
    return switch (category) {
        .ones, .twos, .threes, .fours, .fives, .sixes => score_num(dice, @intFromEnum(category) + 1),
        .full_house => score_full_house(dice),
        .four_of_a_kind => score_four_of_a_kind(dice),
        .little_straight, .big_straight => score_straight(dice, category),
        .choice => score_num(dice, -1),
        .yacht => score_yatch(dice),
    };
}
