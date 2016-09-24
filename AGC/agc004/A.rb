a, b, c = gets.split.map(&:to_i)
ans = [
  (a * b * (c / 2.0).ceil - a * b * (c / 2.0).floor).abs,
  ((a / 2.0).ceil * b * c - (a / 2.0).floor * b * c).abs,
  (a * (b / 2.0).ceil * c - a * (b / 2.0).floor * c).abs
].min

puts ans
