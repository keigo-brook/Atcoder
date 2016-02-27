oa, ab, bc = gets.split.map(&:to_i)
moc = oa + ab + bc

mm = [oa, ab, bc].max
# 一番長い線分がすべての線分の半分以上ならばそのぶんだけ入れない領域がある
if 2 * mm > moc
  im = 2 * mm - moc
else
  im = 0
end
puts (moc ** 2 - im ** 2)*Math::PI