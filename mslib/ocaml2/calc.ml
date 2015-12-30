        (* File calc.ml *)
open Parser;;
open List;;
open String;;
let myconcat x = String.concat "" x;;

let id x = x;;

let closeinquot x = myconcat ["'";x;"'"];;

(* let tostr name explist f = myconcat ["("; String.concat ", " ((myconcat ["'"; name; "'"])::(map f explist)); ")"];;
 *)
let tostr name explist f = myconcat ["("; String.concat ", " ((myconcat ["'"; name; "'"])::(map f explist)); ",)"];;


        let _ =
          try
            let lexbuf = Lexing.from_channel (open_in Sys.argv.(1)) in
            while true do
              let result = Parser.main Lexer.token lexbuf in
              let rec f x = match x with 
              Dictle (y1,y2) -> tostr "Dictle" [y1; y2] f;
              | Binop (op,y1,y2) -> tostr "Binop" [closeinquot op; f y1; f y2] id;
              | None  -> tostr "None" [] id;
              | Ife(y1, y2, y3) -> tostr "Ife" [y1;y2;y3] f;
              | Attr (y1,y2) -> tostr "Attr" [f y1; closeinquot y2] id;
              | Not(y1) -> tostr "Not" [y1] f;
              | Get (y1,y2) -> tostr "Get" [y1; y2] f;
              | Dictl (y1) -> tostr "Dictl" y1 f;
              | Listl (y1) -> tostr "Listl" y1 f;
              | Fcall (fname, y1) -> tostr "Fcall" (fname::y1) f;
              | N (y1) -> tostr "N" [y1] string_of_int;
              | V (y1) -> tostr "V" [closeinquot y1] id;
              | S (y1) -> tostr "S" [y1] id;
              | _ -> "";

            in let rec pstatement x = match x with
              Tag (e1, e2, e3) -> tostr "Tag" [f e1; f e2; pstatement e3] id;
              | Defn (e1, e2, e3) -> tostr "Defn" [f e1; f e2; pstatement e3] id;
              | Forl (e1, e2, e3, e4) -> tostr "Forl" [f e1; f e2; f e3; pstatement e4 ] id;
              | Assign (e1, e2) -> tostr "Assign" [e1;e2] f;
              | Listi e1 -> tostr "Listi" e1 pstatement;
              | Ifel e1 -> tostr "Ifel" (map (function (x1, x2) -> tostr "Ifepair" [f x1; pstatement x2] id) e1) id;
              | _ -> "";


(* type inst = Skip | Tag of (exp*exp*inst) | Defn of (string*exp*(inst list)) | Forl of (string*string*exp*inst) | Listi of ( inst list) | Ifel of ((exp*inst) list) | Assign of (exp*exp);;
 *)

	          in
                print_string (String.concat ",\n" (map pstatement result)); print_newline(); flush stdout
            done
          with Lexer.Eof ->
            exit 0