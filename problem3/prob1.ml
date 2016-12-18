let euler f = Util.calcSSM f

let _ =
  let prob1 _ (x, y, vx, vy) = (vx, vy, y, -1.0 *. x) in
  let dt = 2.0 *. Util.pi /. 64.0 in
  let print (n, state) =
    let (x, y, _, _) = state in
    let t = (float_of_int n) *. dt in
    let error = Util.abs_vector2
      (Util.minus_vector2 (x, y) (-1.0 *. cos(t), sin(t))) in
    Printf.printf "%f\t%f\t%f\t%f\n" t x y error
  in
  let result = euler prob1 dt 320 (0, (-1.0, 0.0, 0.0, 1.0)) in
  print_string "#t x y error\n";
  List.iter print result
