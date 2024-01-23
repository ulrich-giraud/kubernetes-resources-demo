FROM gcc:11 as builder

ADD alloc.c /
RUN gcc alloc.c -o /alloc128

FROM gcr.io/distroless/base-debian11

COPY --from=builder /alloc128 /

ENTRYPOINT ["/alloc128"]