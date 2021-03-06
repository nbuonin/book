(jbuild_version 1)

(alias ((name sexp) (deps (search_with_timeout_no_leak.ml.sexp))))

(rule (
  (targets (search_with_timeout_no_leak.ml.sexp))
  (deps    (search_with_timeout_no_leak.ml))
  (fallback)
  (action (with-stdout-to ${@} (run rwo-build eval ${<})))))

(alias ((name sexp) (deps (jbuild.sexp))))

(rule (
  (targets (jbuild.sexp))
  (deps    (jbuild))
  (fallback)
  (action (with-stdout-to ${@} (run rwo-build eval ${<})))))

(alias ((name sexp) (deps (run_search_with_timeout_no_leak.sh.sexp))))

(rule (
  (targets (run_search_with_timeout_no_leak.sh.sexp))
  (deps (
    run_search_with_timeout_no_leak.sh
    search_with_timeout_no_leak.ml
    jbuild
    jbuild.inc))
  (fallback)
  (action (setenv TERM dumb (with-stdout-to ${@} (run rwo-build eval ${<}))))))

