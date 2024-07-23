const rand = @import("std").Random;

pub fn modifier(score: i8) i8 {
    return @divFloor(score - 10, 2);
}

pub fn ability() i8 {
    var prng = rand.DefaultPrng.init(0);
    const r = prng.random();

    var min: i8 = 7;
    var sum: i8 = 0;
    for (0..4) |_| {
        const roll = r.intRangeAtMost(i8, 1, 6);
        sum += roll;
        if (roll < min) min = roll;
    }
    return sum - min;
}

pub const Character = struct {
    strength: i8 = ability(),
    dexterity: i8 = ability(),
    constitution: i8 = ability(),
    intelligence: i8 = ability(),
    wisdom: i8 = ability(),
    charisma: i8 = ability(),
    hitpoints: i8 = undefined,

    pub fn init() Character {
        var char = Character{};
        char.hitpoints = modifier(char.constitution) + 10;
        return char;
    }
};
