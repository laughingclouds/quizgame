# Alpine-Drogon

Uses alpine 3.15.4 and installs drogon.
Final image size: ~380MB

**Does not** install *everything*. For example, postgres, redis, etc.

Referenced mostly from:

- [Alpine Dockerfile](https://github.com/drogonframework/drogon/blob/master/docker/alpine/Dockerfile) that installs drogon
- [Ubuntu Dockerfile](https://github.com/drogonframework/drogon/blob/master/docker/ubuntu/Dockerfile) that installs drogon

## Build image

Open terminal in *this* folder (project_root/docker/alpine) and run the following

```shell
docker build -t alpine-drogon .
```

And that's it!
