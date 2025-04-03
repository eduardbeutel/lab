# minimal base image that only includes the runtime environment
# inherit specific version of base image
FROM eclipse-temurin:21-jre-alpine-3.21

# create directory for application
RUN mkdir app &&\
    # create group app and user app
    addgroup --gid 1000 -S app && adduser --uid 1000 -S app -G app &&\
    # set permissions for app user for the WORKDIR
    chown -R app:app app/
 # switch to the created user
USER app
# switch to the app dir
WORKDIR /app

# app
ARG JAR_FILE=target/*.jar
COPY ${JAR_FILE} app.jar
ENTRYPOINT ["java","-jar","app.jar"]

# health
# HEALTHCHECK --interval=5s --timeout=3s CMD curl --fail http://localhost:8080/health || exit 1
# HEALTHCHECK  --interval=5s --timeout=3s CMD wget --no-verbose --tries=1 --spider http://localhost:8080/health || exit 1

## autoheal when combined with restart_policy on-failure
# HEALTHCHECK --interval=5s --timeout=3s --start-period=45s CMD curl -f --retry 6 --max-time 5 --retry-delay 10 --retry-max-time 60 "http://localhost:8080/health" || bash -c 'kill -s 15 -1 && (sleep 10; kill -s 9 -1)'
HEALTHCHECK --interval=5s --timeout=3s --start-period=45s CMD wget --no-verbose --tries=1 --spider http://localhost:8080/health || bash -c 'kill -s 15 -1 && (sleep 10; kill -s 9 -1)'