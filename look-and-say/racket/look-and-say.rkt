#lang racket
(define (look-and-say n)
  (look-and-say-helper n 1))

(define (look-and-say-helper n a)
  (if (= n 0)
      a
      (look-and-say-helper (- n 1) (int-from-digits (compute-count (split a))))))

(define (int-from-digits ls)
  (int-from-digits-helper 0 (reverse ls)))

(define (int-from-digits-helper ex ls)
  (if (null? ls)
      0
      (+ (* (car ls) (expt 10 ex)) (int-from-digits-helper (+ ex 1) (cdr ls)))))

(define (split a)
  (reverse (split-helper a)))

(define (split-helper a)
  (if (= a 0)
      '()
      (cons (modulo a 10) (split-helper (floor (/ a 10))))))

(define (compute-count ls)
  (compute-count-helper (cdr ls) (car ls) 1))

(define (compute-count-helper list element run)
  (if (null? list)
      (cons run (cons element '()))
      (if (= element (car list))
          (compute-count-helper (cdr list) element (+ run 1))
          (cons run (cons element (compute-count-helper (cdr list) (car list) 1))))))