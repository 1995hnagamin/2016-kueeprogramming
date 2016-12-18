let _ =
  let scale = 64 in
  let prob1 _ (x, y, vx, vy) = (vx, vy, y, -1.0 *. x) in
  let result = Util.simulate_with_euler prob1 scale in
  Util.print_result result scale
