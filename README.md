# Présentation utilisation des requests et limites

You can run the slideshow on your machine after following a few simple steps:

1. If you haven't already installed Go on your machine, do so by
    following the official [installation instructions][install].

2. Important: make sure that the directory where Go installs binaries
    is in your `PATH` environment variable.
    The directory in question is usually given by the following command:

    ```shell
    echo `go env GOBIN`
    ```
    On macos and linux, it defaults to `$HOME/go/bin`

3. Install the [`present`][present] tool:

    ```shell
    go install golang.org/x/tools/cmd/present@latest
    ```

4. Run the present tool:

    ```shell
    present
    ```

    The output should contain some local URL (like `http://127.0.0.1:3999`).

5. Visit the URL from step 4 in your browser,
    then click on `main.slide` to start the slideshow.

[install]: https://go.dev/doc/install
[present]: https://pkg.go.dev/golang.org/x/tools/cmd/present
