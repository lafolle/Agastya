Copyright (C) 2010 Massachusetts Institute of Technology
This is free software; see the source for copying conditions. There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Image saved on Saturday September 25, 2010 at 5:58:04 PM
  Release 9.0.1 || Microcode 15.1 || Runtime 15.7 || SF 4.41 || LIAR/i386 4.118
  Edwin 3.116
;You are in an interaction window of the Edwin editor.
;Type `C-h' for help, or `C-h t' for a tutorial.
;`C-h m' will describe some commands.
;`C-h' means: hold down the Ctrl key and type `h'.
;Package: (user)



(define (f n)
  (if (= n 1)
      1
      (* n (f (- n 1)))))
;Value: f

;Value: f

(f 10)
9876543210
;Value: 3628800


;Ill-formed special form: (define (- n 1))
;Value: f

(f 10)
;Value: 3628800

(f 100)
;Value: 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

(/ 1 (f 100))
;Value: 1/93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

(/ 1.0 (f 100))
;Value: 1.071510288125467e-158



(define (inc n)
  (+ n 1))
;Value: inc


(define (dec n)
  (- n 1))
;Value: dec



(define (toggle x)
  (if (= x 1)
      -1
      1))




(define (compute n e as ft)
  (if (= n 0)
      e
      (let
	  ((a (+ e (* (toggle as) (/ 1.0 (f ft))))))
	(display ft)
	(compute (dec n) a (toggle as) (inc ft)))))
;Value: compute



(define (ee n)
  (compute n 0 -1 2))
;Value: ee

;Value: ee

(ee 50)
23456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051
;Value: .36787944117144245

5049484746454443424140393837363534333231302928272625242322212019181716151413121110987654321
;Value: .36787944117144245




1-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-1
;Value: .36787944117144245

-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11-11
;Value: .36787944117144245















