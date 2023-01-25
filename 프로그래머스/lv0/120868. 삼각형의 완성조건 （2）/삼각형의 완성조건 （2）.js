function solution(sides) {
    let answer = [];
    sides.sort((a, b) => a - b);
    for (let i = 1; i <= 2000; i++) {
        if (sides[1] >= i) {
            if (sides[1] < i + sides[0]) answer.push(i);
        }
        if (sides[1] < i) {
            if (i < sides[0] + sides[1]) answer.push(i);
        }
    }
    return answer.length;
}